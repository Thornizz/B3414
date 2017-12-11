import java.net.*;

public class Multicast
{
	private final String IP = "239.255.80.84";
	private final int PORT = 8888;
	private String pseudo;
	
	public Multicast(String pseudo)
	{
		try
		{
			this.pseudo = pseudo;
	    	System.out.println("##### Fenêtre de "+this.pseudo+" #####"+'\n');
	    	MulticastSocket s = new MulticastSocket(PORT);
	    	s.joinGroup(InetAddress.getByName(IP));
	    	
	    	new ThreadListeningClient(s);	    	
	    	
	    	String msg = "Hello"+pseudo;
	    	DatagramPacket dp = new DatagramPacket(msg.getBytes(),msg.length(),InetAddress.getByName(IP),PORT);
	    	s.send(dp);
	    	System.out.println("Envoie : "+msg);
		}
		catch (Exception e)
		{
			System.err.println("Error in Multicast::Multicast:" + e);			
		}
    }
	
	public static void main(String Args[])
	{
		new Multicast("JJ");
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
import java.net.*;

public class ThreadListeningClient extends Thread
{

	private MulticastSocket s;
	
	public ThreadListeningClient(MulticastSocket s)
	{
		this.s = s;
		this.start();
	}
	
	public void run()
	{
	    byte[] buf = new byte[1000];
	    DatagramPacket recv = new DatagramPacket(buf,buf.length);
		try
		{
    		while (true) {
    	    	s.receive(recv);
    	    	String recu = new String(buf);
    	    	System.out.println(recu);
    		}
    	}
		catch (Exception e) {
        	System.err.println("Error in ThreadListeningClient::run :" + e); 
        	e.printStackTrace();
    	}
	}
}