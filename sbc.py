import serial 
import socket
import time

arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

HOST = ''
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
  s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
  s.bind((HOST, PORT))
  s.listen()
  conn, addr = s.accept()
  with conn:
    print('Connected by', addr)
    while True:
      try:
        data = arduino.readline()
        if data:
          conn.sendall(data)
        time.sleep(0.1)
      except Exception as e:
        print(e)
        arduino.close() 
        break
