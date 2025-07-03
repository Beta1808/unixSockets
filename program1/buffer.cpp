#include "buffer.h"

void Buffer::setString(const std::string& input) {
	std::unique_lock<std::mutex> lock(bufferMutex_);
	
	buffer_ = input;
	
	charCount_.clear();
	for (const char& ch : buffer_)
		charCount_[ch]++;
	
	bufferCondVar_.notify_one();
}

std::map<char, unsigned> Buffer::getProcessedData() {
	std::unique_lock<std::mutex> lock(bufferMutex_);
	return charCount_;
}

void Buffer::clearBuffer() {
	std::unique_lock<std::mutex> lock(bufferMutex_);
	buffer_.clear();
	charCount_.clear();
}

bool Buffer::isEmpty() {
	return (buffer_.size() == 0 && charCount_.size() == 0);
}

void Buffer::waitForData() {
	std::unique_lock<std::mutex> lock(bufferMutex_);
	bufferCondVar_.wait(lock, [this] { return !isEmpty(); });
}