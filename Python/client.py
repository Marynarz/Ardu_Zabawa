#!/usr/bin/env python3

#chmod +x server.py!

import socket
import sys

# Tworzenie gniazda TCP/IP
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#deklaracia adresu - moze byc jako lista
adress = ('localhost',9999)
print("Start na adresie:",adress)
sock.connect(adress)

try:
    message = 'Ja pierdole! Kurwa mac!'
    print('Wysylanie: ',message)
    sock.sendall(message)
    
    odebrane = 0
    oczekiwane = len(message)
    
    while odebrane < oczekiwane:
        data = sock.recv(16)
        odebrane += len(data)
        print('Odebrano : ',data)
    
finally:
    print("Klient sie skonczyl!")
    sock.close()
