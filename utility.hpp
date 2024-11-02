#ifndef UTILITY_H
#define UTILITY_H
#include "__internal/headers.hpp"
#include "__internal/global.hpp"
void stacktrace(const char* module, const char* msg, ...) {
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
namespace random {
	[[nodiscard]] int32_t int32(void) {
		std::random_device rd;
		std::mt19937_64 mt(rd());
		return mt();
	}
};
#endif /* UTILITY_H */