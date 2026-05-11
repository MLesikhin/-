# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2
TARGET = a.out

# Объектные файлы
OBJS = main.o sorts.o HW1.o

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Компиляция main.cpp
main.o: main.cpp sorts.h HW1.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Компиляция sorts.cpp
sorts.o: sorts.cpp sorts.h
	$(CXX) $(CXXFLAGS) -c sorts.cpp

# Компиляция HW1.cpp
HW1.o: HW1.cpp HW1.h
	$(CXX) $(CXXFLAGS) -c HW1.cpp

# Очистка
clean:
	rm -f $(OBJS) $(TARGET)
