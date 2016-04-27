echo "Compiling Sources ..."

#server
g++ -std=c++11 ServerSocket.cpp Socket.cpp simple_server_main.cpp -o server
#client
g++ -std=c++11 ClientSocket.cpp Socket.cpp simple_client_main.cpp -o client

echo "Done."