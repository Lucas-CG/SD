echo "Compiling Sources ..."

#server
g++ -std=c++11 ServerSocket.cpp Socket.cpp Server.cpp -o server
#client
g++ -std=c++11 ClientSocket.cpp Socket.cpp Client.cpp -o client

echo "Done."