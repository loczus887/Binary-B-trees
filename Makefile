# Nazwa projektu
TARGET = drzewo

# Kompilator i flagi kompilacji
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Pliki źródłowe
SRCS = drzewo.cpp

# Pliki obiektowe
OBJS = $(SRCS:.cpp=.o)

# Tworzenie pliku wykonywalnego
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Kompilacja plików obiektowych
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Czystość projektu
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean

