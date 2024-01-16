#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ), error_(false), byteStream(),
 isFinished_(false), bytes_read(0), bytes_written(0) {}

bool Writer::is_closed() const
{
  return isFinished_;
}

void Writer::push( string data )
{
  (void)data;
  int cur_char = 0;
  while (capacity_ != 0) {
    byteStream.push_back(data[cur_char]);
    cur_char++;
    bytes_written++;
    capacity_--;
  }
  return;
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
  if (isFinished_) {
    return (bytes_written == bytes_read);
  }
  return false;
}

uint64_t Reader::bytes_popped() const
{
  return bytes_read;
}

string_view Reader::peek() const
{
  if (byteStream.size() > 0) {
    return string_view(&byteStream[0], byteStream.size());//byteStream[byteStream.size() - 1];
  } else {
    return string_view(); 
  }
}

void Reader::pop( uint64_t len )
{
  (void)len;
  uint64_t count = 0;
  for (int i = (byteStream.size() - 1) ; i >= 0; i--) {
    if (count == len) {
      break;
    }
    byteStream.erase(byteStream.begin() + i);
    count++;
    capacity_++;
  }
  bytes_read += count;
}

uint64_t Reader::bytes_buffered() const
{
  return bytes_written - bytes_read;
}
