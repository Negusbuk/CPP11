TARGETS = auto01 \
          auto02 \
          array01 \
          list_initialization01 \
          unordered_set01 \
          unordered_multiset01 \
          unordered_map01 \
          unordered_multimap01 \
          unordered_map02 \
          async01 \
          package_task01 \
          promise01 \
          thread01 \
          thread02 \
          thread03 \
          thread04 \
          thread05 \
          thread06 \
          move01 \
          move02 \
          tuple01 \
          smartptr01 \
          smartptr02 \
          smartptr03 \
          smartptr04 \
          smartptr05 \
          lambda01 \
          forward01
          
all: $(TARGETS)

%: %.cc
	clang++ -stdlib=libc++ -std=c++11 -o $@ $<

clean:
	rm -f $(TARGETS)
