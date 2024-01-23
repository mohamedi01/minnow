#include "reassembler.hh"

using namespace std;

void Reassembler::insert( uint64_t first_index, string data, bool is_last_substring )
{
  (void)first_index;
  (void)data;
  (void)is_last_substring;
  
  if (writer().is_closed()) return; // if the reassembler is already full

  first_idx_ = reader().bytes_popped(); // moving to first unpopped index
  curr_idx_ = writer().bytes_pushed(); // moving to first unassembled index
  final_idx_ = curr_idx_ + writer().available_capacity(); // first unacceptable index

  if (curr_idx_ == first_index) {
    output_.writer().push(data);
    if (is_last_substring) {
      output_.writer().close();
    }
  } else {
    if (first_index > curr_idx_) waiting_[first_index] = data;
    if (waiting_.find(curr_idx_) != waiting_.end()) {
      output_.writer().push(waiting_[curr_idx_]);
      waiting_.erase(curr_idx_);
    } else {
      return;
    }
  }
}

uint64_t Reassembler::bytes_pending() const
{
  return waiting_.size();
}
