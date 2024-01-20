#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity )
  : capacity_( capacity )
  , error_( false )
  , myByteStream()
  , isFinished_( false )
  , bytes_read( 0 )
  , bytes_written( 0 )
{}

bool Writer::is_closed() const
{
  return isFinished_;
}

void Writer::push( string data )
{
  (void)data;
  std::string sub_data = data.substr( 0, capacity_ );
  myByteStream += sub_data;
  capacity_ -= sub_data.size();
  bytes_written += sub_data.size();
}

void Writer::close()
{
  isFinished_ = true;
}

uint64_t Writer::available_capacity() const
{
  return capacity_;
}

uint64_t Writer::bytes_pushed() const
{
  return bytes_written;
}

bool Reader::is_finished() const
{
  if ( isFinished_ ) {
    return ( bytes_written == bytes_read );
  }
  return false;
}

uint64_t Reader::bytes_popped() const
{
  return bytes_read;
}

string_view Reader::peek() const
{
  if ( myByteStream.size() > 0 ) {
    return myByteStream;
  } else {
    return string_view();
  }
}

void Reader::pop( uint64_t len )
{
  (void)len;
  uint64_t hold = min( myByteStream.size(), len );
  myByteStream = myByteStream.substr( hold, myByteStream.size() );
  bytes_read += hold;
  capacity_ += hold;
}

uint64_t Reader::bytes_buffered() const
{
  return bytes_written - bytes_read;
}
