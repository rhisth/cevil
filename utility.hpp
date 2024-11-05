#ifndef UTILITY_H
#define UTILITY_H
#include "__internal/headers.hpp"
#include "__internal/global.hpp"
void stacktrace(const char* module, const char* msg, ...) {
	if (gl::logfile == nullptr) {
		return;
	}
	time_t get_time = time(NULL);
	struct tm* timeinfo;
	char current_time[80];
	timeinfo = localtime(&get_time);
	strftime(current_time, sizeof(current_time), "%Y-%m-%d // %H:%M:%S", timeinfo);
	fprintf(gl::logfile, "[%s] [%s] ", current_time, module);
	va_list args;
	va_start(args, msg);
	vfprintf(gl::logfile, msg, args);
	va_end(args);
	fputc('\n', gl::logfile);
}
uint32_t get_CRC(_iobuf* file) {
	uint32_t CRC = 0xFFFFFFFF;
	unsigned char buffer[4096];
	size_t bytes_read;
	while ((bytes_read = fread(buffer, 1, 4096, file)) > 0) {
		for (size_t i = 0; i < bytes_read; i++) {
			uint8_t byte = buffer[i];
			CRC = (CRC >> 8) ^ gl::CRC_table[(CRC ^ byte) & 0xFF];
		}
	}
	fclose(file);
	return CRC ^ 0xFFFFFFFF;
}
namespace random {
	int32_t int32(void) {
		std::random_device rd;
		std::mt19937 mt(rd());
		return mt();
	}
};
#endif /* UTILITY_H */