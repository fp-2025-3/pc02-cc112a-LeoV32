# Flags para AddressSanitizer
ASANFLAGS := -fsanitize=address -g

# Regla ASAN: compila todos los cpp con sanitizer
asan:
	$(CXX) $(CXXFLAGS) $(ASANFLAGS) $(SRCS)

