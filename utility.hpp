#ifndef UTILITY_H
#define UTILITY_H
#include "__internal/preprocessor.hpp"
#include "__internal/global.hpp"
#ifdef CXX17
template <typename... T>
#else
template <typename T> concept is_string = std::is_convertible_v<T, cstr_t> || std::is_convertible_v<T, str_t>;
template <is_string... T>
#endif /* CXX17 */
void stacktrace(cstr_t _module, T... msg) {
#ifdef CXX17
	static_assert((std::is_same_v<const char*, T>, ...) || (std::is_same_v<char*, T>, ...), "All arguments must be of type \"const char*\" or \"char*\"");
#endif /* CXX17 */
	if (gl::logfile == nullptr) {
		return;
	}
	char current_time[80];
#ifdef CXX17
	time_t get_time = time(NULL);
	struct tm* timeinfo;
	timeinfo = localtime(&get_time);
	strftime(current_time, sizeof(current_time), "%Y-%m-%d // %H:%M:%S", timeinfo);
#else
	const std::chrono::time_point now = std::chrono::system_clock::now();
	const std::chrono::time_point days = std::chrono::floor<std::chrono::days>(now);
	const std::chrono::year_month_day ymd = days;
	const std::chrono::hh_mm_ss time{
		std::chrono::floor<std::chrono::milliseconds>(now - days)
	};
	sprintf(current_time, "%04i-%02i-%02i // %02i:%02i:%02i",
		static_cast<int>(ymd.year()),
		static_cast<unsigned>(ymd.month()),
		static_cast<unsigned>(ymd.day()),
		static_cast<unsigned>(time.hours().count()),
		static_cast<unsigned>(time.minutes().count()),
		static_cast<unsigned>(time.seconds().count())
	);
#endif /* CXX 17 */
	fprintf(gl::logfile, "[%s] [%s] ", current_time, _module);
	(fprintf(gl::logfile, "%s", msg), ...);
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
#endif /* UTILITY_H */