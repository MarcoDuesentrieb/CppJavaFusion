#include <jni.h>
#include <iostream>
#include <thread>


void task()
{
	JavaVMOption jvmopt[1];
    jvmopt[0].optionString = const_cast<char *>("-Djava.class.path=../java");

    JavaVMInitArgs vmArgs;
    vmArgs.version = JNI_VERSION_1_2;
    vmArgs.nOptions = 1;
    vmArgs.options = jvmopt;
    vmArgs.ignoreUnrecognized = JNI_TRUE;

    // Create the JVM
    JavaVM *javaVM;
    JNIEnv *jniEnv;
    long flag = JNI_CreateJavaVM(&javaVM, (void **)
            &jniEnv, &vmArgs);
          
    // try to find the class
    const char javaClassName[] = "TickTock";  
    jclass javaClass = jniEnv->FindClass(javaClassName);  
	if(javaClass == nullptr) 
	{
		std::cerr << "ERROR: class \"" << javaClassName << "\" not found!" << std::endl;
	}
	else
	{
		std::cout << "SUCCESS: Class \"" << javaClassName << "\" found!" << std::endl;
		const char javaMethodName[] = "start"; 
		jmethodID mid = jniEnv->GetStaticMethodID(javaClass, javaMethodName, "()V");  // find method
		if(mid == nullptr)
			std::cerr << "ERROR: Method \"" << javaMethodName << "\" not found!" << std::endl;
		else
		{
			jniEnv->CallStaticVoidMethod(javaClass, mid); // call method
		}
    }
}


int main()
{ 
	// start java vm in separate thread to achieve non-blocking behavior
	std::thread t1(task);
	
	using namespace std::literals::chrono_literals;

	while(true)
	{
		std::cout << "While loop in main() is running" << std::endl;
		std::this_thread::sleep_for(3000ms);
	}
 
    return 0;      
}
