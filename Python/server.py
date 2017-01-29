#!/usr/bin/env python3

#chmod +x server.py!

import socket
import sys

# Tworzenie gniazda TCP/IP
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#deklaracia adresu - moze byc jako lista
adress = ('localhost',9999)
print("Start na adresie:",adress)

#nasluchujemy
sock.bind(adress)
sock.listen(1)

while True:
    print('Czekamy na polaczenie')
    connection,client_addres = sock.accept()
    try:
        print('Polaczenie z:',client_addres)
        
        while True:
            data = connection.recv(16)
            print('Odebrano: ',data);
            if data:
                connection.sendall(data)
            else:
                break
    finally:
        connection.close()
