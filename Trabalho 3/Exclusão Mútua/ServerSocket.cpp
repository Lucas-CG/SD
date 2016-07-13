// Implementation of the ServerSocket class

#include "ServerSocket.h"
#include "SocketException.h"
#include <iostream>

using namespace std;

ServerSocket::ServerSocket ( int port )
{
  if ( ! Socket::create() )
    {
      throw SocketException ( "Não foi possível criar o socket do servidor." );
    }

  if ( ! Socket::bind ( port ) )
    {
      throw SocketException ( "Não foi possível bind com a porta." );
    }

  if ( ! Socket::listen() )
    {
      throw SocketException ( "Não foi possível escutar do socket." );
    }

}

ServerSocket::~ServerSocket()
{
}


const ServerSocket& ServerSocket::operator << ( const std::string& s ) const
{
  if ( ! Socket::send ( s ) )
    {
      throw SocketException ( "Não foi possível escrever no socket." );
    }

  return *this;

}


const ServerSocket& ServerSocket::operator >> ( std::string& s ) const
{
  if ( ! Socket::recv ( s ) )
    {
      throw SocketException ( "Não foi possível ler do socket." );
    }

  return *this;
}

void ServerSocket::accept ( ServerSocket& sock )
{
  if ( ! Socket::accept ( sock ) )
    {
      throw SocketException ( "Não foi possível aceitar o socket." );
    }
}
