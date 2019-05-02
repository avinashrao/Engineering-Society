import os
import serial
import time
i=0
ser = serial.Serial('/dev/tty.usbserial-14310' ,9600)
while 1:
    message = input("What command? \n")

    if(message == "shoulder up"):
        ser.write(bytes("A", encoding='utf-8'))
    if(message == "shoulder down"):
        ser.write(bytes("B", encoding='utf-8'))
    if(message == "elbow up"):
        ser.write(bytes("C", encoding='utf-8'))
    if(message == "elbow down"):
        ser.write(bytes("D", encoding='utf-8'))
    if(message == "wrist up"):
        ser.write(bytes("E", encoding='utf-8'))
    if(message == "wrist down"):
        ser.write(bytes("F", encoding='utf-8'))
    if(message == "wrist clockwise"):
        ser.write(bytes("G", encoding='utf-8'))   
    if(message == "wrist counterclockwise"):
        ser.write(bytes("H", encoding='utf-8'))
    if(message == "gripper open"):
        ser.write(bytes("I", encoding='utf-8'))
    if(message == "gripper close"):
        ser.write(bytes("J", encoding='utf-8'))    
    if(message == "base clockwise"):
        ser.write(bytes("K", encoding='utf-8'))
    if(message == "base counterclockwise"):
        ser.write(bytes("L", encoding='utf-8'))