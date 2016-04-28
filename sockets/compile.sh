#!/bin/bash
echo "Compiling Sources..."

#server
g++ -std=c++11 ServerSocket.cpp Socket.cpp Servidor.cpp -o servidor
#client
g++ -std=c++11 ClientSocket.cpp Socket.cpp Cliente.cpp -o cliente

echo "Done."