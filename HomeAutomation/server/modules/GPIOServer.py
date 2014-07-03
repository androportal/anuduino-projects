#!/usr/bin/env python
# coding: utf8
from socket import *
import RPi.GPIO as GPIO

SETUP = chr(0)
OUTPUT = chr(1)

GPIO.setmode(GPIO.BCM)

def gpio_setup(data):
    pin,dir = ord(data[0]),ord(data[1])
    GPIO.setup(pin,dir)
    print "setup",pin,dir
    return 0
    
def gpio_output(data):
    pin,val = ord(data[0]),ord(data[1])
    GPIO.output(pin,val)
    print "out",pin,val
    return 0
    
if __name__=='__main__':
    HOST = 'localhost'
    PORT = 21567
    BUFSIZ = 1024
    ADDR = (HOST, PORT)
    serversock = socket(AF_INET, SOCK_STREAM)
    serversock.bind(ADDR)
    serversock.listen(2)

    while 1:
        ret = None
        print 'waiting for connection...'
        clientsock, addr = serversock.accept()
        print '...connected from:', addr
        data = clientsock.recv(BUFSIZ)
        if data[0] == SETUP:
            ret = gpio_setup(data[1:])
        elif data[0] == OUTPUT:
            ret = gpio_output(data[1:])
            
        if  ret:
            clientsock.send(ret)
            clientsock.close()
