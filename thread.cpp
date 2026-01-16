#include <mutex>
#include <thread>
#include <cstdio>


int counter = 0;
std::mutex mtx;

void add10000(){
	for(int i=0; i<10; i++) {
		mtx.lock();
		counter++;
		printf("counter is %d\n", counter);
		mtx.unlock();
	}
}
// 这是一个纯鼠标提交
int main(){
	std::thread t1(add10000);
	std::thread t2(add10000); 
	t1.join();
	t2.join();
	printf("counter is %d\n", counter);
	
	return 0;
}
