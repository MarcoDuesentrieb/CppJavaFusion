
public class TickTock {
    public static void start(){
        System.out.println("Hello from Java!");
        Thread t1 = new Thread(new myThreadRoutine(), "Tick");
        Thread t2 = new Thread(new myThreadRoutine(), "Tock");
        t1.start();
        try {
            Thread.sleep(1000);
        }
        catch(Exception e){
            //do nothing
        }
        t2.start();
        try{
            t1.join();
            t2.join();
        }
        catch(Exception e){
            System.out.println("Joining threads failed!");
        }
    }
}

class myThreadRoutine implements Runnable {

    @Override
    public void run() {
        System.out.println("Thread \"" + Thread.currentThread().getName() +"\" started.");
        try{
            while(true) {
                Thread.sleep(2000);
                System.out.println(Thread.currentThread().getName());
            }
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }
}
