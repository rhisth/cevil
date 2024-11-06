#ifndef GLOBAL_H
#define GLOBAL_H
#include "preprocessor.hpp"
#include "types.hpp"
constexpr struct {
	cstr_t core = "CORE";
	cstr_t warn = "WARNING";
	cstr_t ios = "I/O";
	cstr_t audio = "AUDIO";
	cstr_t render = "RENDER";
	cstr_t net = "NET";
} _module;
namespace gl {
	_iobuf* logfile = []() {
		_iobuf* file = fopen("../stacktrace.log", "a");
		if (!file) {
			file = nullptr;
			perror("---Couldn't open \"stacktrace.log\"---");
		}
		return file;
	}.operator()();
	constinit uint16_t fps = 60;
	constexpr std::array<uint32_t, 256> CRC_table = [](void) {
		uint32_t CRC;
		std::array<uint32_t, 256> table = {};
		for (uint32_t i = 0; i < 256; i++) {
			CRC = i;
			for (uint32_t j = 8; j > 0; j--) {
				if (CRC & 1) {
					CRC = (CRC >> 1) ^ 0xEDB88320;
				} else {
					CRC >>= 1;
				}
			}
			table[i] = CRC;
		}
		return table;
	}.operator()();
}
#endif /* GLOBAL_H */