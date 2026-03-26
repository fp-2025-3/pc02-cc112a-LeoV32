# Compilador
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic

# Buscar automáticamente todos los .cpp
SRCS := $(wildcard *.cpp)

# Generar los ejecutables correspondientes
TARGETS := $(SRCS:.cpp=.exe)

# Regla por defecto
all: $(TARGETS)

# Regla genérica: cpp -> exe
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@


# AddressSanitizer
ASAN_FLAGS := -fsanitize=address -g

asan: CXXFLAGS += $(ASAN_FLAGS)
asan: clean all



# Limpiar ejecutables
clean:
	rm -f *.exe




# Automatización real
# Cada programa es independiente
# El compilador y flags no se eligen al azar
# No compilar “a mano” con comandos distintos

# Evitamos
# Copiar/pegar comandos 
# Ejecutables desactualizados
# Flags inconsistentes


