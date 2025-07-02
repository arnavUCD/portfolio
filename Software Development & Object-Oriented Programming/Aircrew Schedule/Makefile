CXXFLAGS = -Wall

all: scheduling testAircrew

scheduling: scheduling.o Aircrew.o
	$(CXX) -o $@ $^

testAircrew: testAircrew.o Aircrew.o
	$(CXX) -o $@ $^

clean:
	rm -f scheduling testAircrew *.o
