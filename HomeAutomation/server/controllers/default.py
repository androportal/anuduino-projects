# -*- coding: utf-8 -*-
import os
import time

@auth.requires_login()
def index():
    lights = db(db.lights.logged_in_user_id==auth.user_id).select()
    return locals()


@auth.requires_login()
@request.restful()
def api():
   def GET(s):
        if s=='on_off':
            comms = db(db.auth_user.id==auth.user_id).select()
            for each in comms: return each.sendString
        elif 'ack' in s and len(s) == 8:
            return 'submitting response'
        else:
            return 'blocked'
   return locals()


@auth.requires_login()
def toggle():   
    light = db(db.lights.id==request.args(0,cast=str)).select().first()
    if light.State:
       light.update_record(State = False)
       if str(auth.user_id)==str(light.logged_in_user_id):
           db(db.auth_user.id == auth.user_id).update(sendString=str(light.device_id) + str(light.State))
       #    light.update_record(sendString=str(light.device_id) + str(light.State))
       redirect(URL('index'))
       #redirect(URL('api/get_status'))
    
    else:
        light.update_record(State = True)
        if str(auth.user_id)==str(light.logged_in_user_id):
           db(db.auth_user.id == auth.user_id).update(sendString=str(light.device_id) + str(light.State))
          # light.update_record(sendString=str(light.device_id) + str(light.State))
        redirect(URL('index'))
    db.commit()
    return URL('index')
    

def user():
    return dict(form=auth())

@auth.requires_login()
def data():
    return dict(form=crud())
