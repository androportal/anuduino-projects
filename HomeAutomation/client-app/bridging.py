#!/usr/bin/python

"""
Storyboard:
Check continously `url_on_off` with 0.5s interval.

When on/off receives instruction,should stop checking `url_on_off`
and send the code to master module through serial, and must send
the `ack-xxx9` through url_on_off_ack.

In each 1min check the status of the device and update server.

Addons:
-p : update username passwd and store internally to a file
"""

import urllib2
import serial
import os
from time import sleep

available_serial_ports = ['/dev/ttyACM0', '/dev/ttyUSB0',
                          '/dev/ttyACM1', '/dev/ttyUSB1',
                          '/dev/ttyACM4', '/dev/ttyUSB2',
                            ]

def find_serial():
    for port in available_serial_ports:
        if os.path.exists(port):
            return port

serial_port = find_serial()
awrite = serial.Serial(serial_port,19200,timeout=2)
sleep(2)

u='srikant'
p='12345'

previous_on_off_status='FIRST_TIME'

#url_on_off='http://127.0.0.1:8000/buttons/default/api/on_off'
#url_on_off='http://192.168.43.156:8000/buttons/default/api/on_off'
url_on_off='https://10.101.11.108:8001/buttons/default/api/on_off'
url_on_off_ack='http://127.0.0.1:8000/buttons/default/api/ack-ccc9'
url_update_status='http://127.0.0.1:8000/buttons/default/api/status'

# simple wrapper function to encode the username & pass
def encodeUserData(user, password):
    return "Basic " + (user + ":" + password).encode("base64").rstrip()


def server2master_master2slave_return_ack(present_on_off_status):
    if 'False' in present_on_off_status:
       serial_port = find_serial()
       awrite = serial.Serial(serial_port,19200,timeout=1)
       sleep(1)
       print present_on_off_status, '1'
       turnOff_string = present_on_off_status.strip('False') + '9'
       print turnOff_string
       for each in range(1,3):
           awrite.writelines(turnOff_string)
           print turnOff_string, '1'
           off_ack_string = awrite.readlines()
           if len(off_ack_string) is 2:
               stripped_off_ack = off_ack_string[1].strip('\r\n')
           else:
               stripped_off_ack= 'N'
 #          print off_ack_string[1].strip('\r\n'), '3',present_on_off_status.strip('False') + '1'
           if stripped_off_ack == (present_on_off_status.strip('False') + '1'):
               print stripped_off_ack, '4'
               return off_ack_string[1].strip('\r\n')
               break

    elif 'True' in present_on_off_status:
       serial_port = find_serial()
       awrite = serial.Serial(serial_port,19200,timeout=1)
       sleep(1)
       print present_on_off_status, '1'
       turnOn_string = present_on_off_status.strip('True') + 'B'
       print turnOn_string
       for each in range(1,4):
           awrite.writelines(turnOn_string)
           on_ack_string = awrite.readlines()
           if len(on_ack_string) is 2:
               stripped_on_ack = on_ack_string[1].strip('\r\n')
           else:
               stripped_on_ack= 'N'
   #         print on_ack_string[1].strip('\r\n'), '3',present_on_off_status.strip('True') + '3'
           if stripped_on_ack == (present_on_off_status.strip('True') + '3'):
              print stripped_on_ack, '4'
              return on_ack_string[1].strip('\r\n')
              break

    if 'Status' in present_on_off_status:
       serial_port = find_serial()
       awrite = serial.Serial(serial_port,19200,timeout=2)
       sleep(2)
       print present_on_off_status, '1'
       status_string = present_on_off_status.strip('Status') + 'F'
       print status_string
       for each in range(1,2):
           awrite.writelines(status_string)
 #          sleep(1)
           while True:
               status_ack_string = awrite.readline()
 #              sleep(1)
               print on_ack_string, '3'
               if status_ack_string.strip('\r\n') == (present_on_off_status.strip('Status') + '7'):
                   print on_ack_string, '4'
                   return status_ack_string.strip('\r\n')


def set_headers(url):
    # create the request object and set some headers
    req = urllib2.Request(url)
    req.add_header('Accept', 'application/json')
    req.add_header("Content-type", "application/x-www-form-urlencoded")
    req.add_header('Authorization', encodeUserData(u, p))
    res=urllib2.urlopen(req)
    return res.read()

def check_on_off(url_on_off):
    global previous_on_off_status
    while True:
        present_on_off_status = set_headers(url_on_off)
        if not present_on_off_status == previous_on_off_status:
            previous_on_off_status = present_on_off_status
            ack_from_master = server2master_master2slave_return_ack(present_on_off_status)
            print ack_from_master
        else:
            previous_on_off_status=present_on_off_status
        sleep(0.5)

if __name__ == "__main__":
    check_on_off(url_on_off)
    awrite.close()
