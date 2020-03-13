#the Python Script was provided by : Jonathan De La Cruz https://www.linkedin.com/in/jonathandelacruz96/


import re
import subprocess
import time
import serial
while True:
    dylan = 1
    lewis = 1
    lydia = 1
    justin = 1
    adr = []
    ser = serial.Serial('/dev/ttyUSB0') #serial
        # this runs commands in terminal that use nmap to print all terminal results into output.txt
    with open('output.txt', 'w') as f:
            p1 = subprocess.run(['sudo', 'nmap', '-sP', '***.*.*.0/**'], stdout=f, text=True)#i use stars to blank out my actual IP, replace with you own
            with open('output.txt', 'r') as searchFile:
                for line in searchFile:
                    if 'MAC' in line:
                        adr.append(line.rstrip('\n'))
            with open('macAddresses.txt', 'w') as macFile:
                    for mac in adr:
                        macFile.write('%s\n' %mac[:30])
    time.sleep(10)             
    with open('macAddresses.txt', 'r') as macFile:
                time.sleep(2)
    with open('macAddresses.txt', 'r') as macFile:
                print('checking who is home...')
                for line in macFile:
                    if '**:**:**:**:**:**' in line:  #i use **:**:**:**:**:** to replace a real MAC address, replace with you own
                        dylan = 2
                        print('Dylan is here') #change this to whatever you want to happen
                        ser.write(b'D') #sends character cast as byte over serial
                if dylan == 1 :
                    print('              Dylan is not here') #change this to whatever you want to happen
                    ser.write(b'd') #sends character cast as byte over serial
    time.sleep(2)
    with open('macAddresses.txt', 'r') as macFile:
                for line in macFile:
                    if '**:**:**:**:**:**' in line:#i use **:**:**:**:**:** to replace a real MAC address, replace with you own
                        lewis = 2
                        print('Lewis is here') #change this to whatever you want to happen
                        ser.write(b'L') #sends character cast as byte over serial
                if lewis == 1:
                    print('              Lewis is not here') #change this to whatever you want to happen
                    ser.write(b'l') #sends character cast as byte over serial
    time.sleep(2)
    with open('macAddresses.txt', 'r') as macFile:
                for line in macFile:
                    if '4**:**:**:**:**:**' in line:#i use **:**:**:**:**:** to replace a real MAC address, replace with you own
                        lydia = 2
                        print('Lydia is here') #change this to whatever you want to happen
                        ser.write(b'K') #sends character cast as byte over serial
                if lydia == 1 :  
                    print('             lydia is not here') #change this to whatever you want to happen
                    ser.write(b'k') #sends character cast as byte over serial
    time.sleep(2)
    with open('macAddresses.txt', 'r') as macFile:
                for line in macFile:
                    if '**:**:**:**:**:**' in line:#i use **:**:**:**:**:** to replace a real MAC address, replace with you own
                        justin = 2
                        print('Justin is here') #change this to whatever you want to happen
                        ser.write(b'J') #sends character cast as byte over serial
                if justin == 1 :
                    print('             justin is not here') #change this to whatever you want to happen
                    ser.write(b'j') #sends character cast as byte over
    time.sleep(2)
    print('end of loop')
    ser.close()
    time.sleep(10)