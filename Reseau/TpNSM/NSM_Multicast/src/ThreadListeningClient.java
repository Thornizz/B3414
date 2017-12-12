import java.net.*;

public class ThreadListeningClient extends Thread
{

	private MulticastSocket s;
	private Client c;
	
	public ThreadListeningClient(MulticastSocket s, Client c)
	{
		this.s = s;
		this.c = c;
		this.start();
	}
	
	public void run()
	{
		try
		{
    		while (true) {
    		    byte[] buf = new byte[1000];
    		    DatagramPacket recv = new DatagramPacket(buf,buf.length);
    	    	s.receive(recv);
    	    	String recu = new String(buf);
    	    	System.out.println("RECU : "+recu);
    	    	c.affiche(recu);
    		}
    	}
		catch (Exception e) {
        	System.err.println("Error in ThreadListeningClient::run :" + e); 
        	e.printStackTrace();
    	}
	}
}