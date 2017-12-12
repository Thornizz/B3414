import java.io.*;
import java.net.Socket;
import java.util.ArrayList;

public class Server
{
	final public static String DECONNEXION = "deco";
	final public static String IP = "127.0.0.1";
	final public static int PORT = 5001;
	final private String FICHIER_HISTORIQUE = "src\\historique.txt";
	
	private ArrayList<Socket> sockets;
	private String historique;
	private IHMServer ihmServer;
	
	public Server(int port, IHMServer ihmServer)
	{
		this.ihmServer = ihmServer;
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(new FileInputStream(FICHIER_HISTORIQUE)));
			
			historique = "";
			String ligne;
			while ((ligne=br.readLine())!=null){
				historique+=ligne+"\n";
			}
			br.close();
		}
		catch (Exception e) {
			System.err.println("Error in Server::Server:" + e);
			ihmServer.affiche("");
			ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			ihmServer.affiche("~~~~~~~~~~ ERREUR ~~~~~~~~~~");
			ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			ihmServer.affiche("");
	    }

		try
		{
			BufferedWriter bw = new BufferedWriter (new OutputStreamWriter (new FileOutputStream (FICHIER_HISTORIQUE)));
			bw.write(historique);
			bw.close();

			ihmServer.affiche("##### Lecture de l'historique :");
			ihmServer.affiche(historique);
		}
		catch (Exception e) {
			System.err.println("Error in Server::Server:" + e);
			ihmServer.affiche("");
			ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			ihmServer.affiche("~~~~~~~~~~ ERREUR ~~~~~~~~~~");
			ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			ihmServer.affiche("");
	    }

		sockets = new ArrayList<Socket>();
		
		ThreadWaitingServer threadWaitingServer = new ThreadWaitingServer(this,PORT,this.ihmServer);
		threadWaitingServer.start();
	}
		
	public void envoyer (String texte)
	{
		historique += texte + '\n';
		try
		{
			BufferedWriter bw = new BufferedWriter (new OutputStreamWriter (new FileOutputStream (FICHIER_HISTORIQUE)));
			bw.write(historique);
			bw.close();
		}
		catch (Exception e)
		{
				System.err.println("Error in Server::envoyer:" + e);
				ihmServer.affiche("");
				ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				ihmServer.affiche("~~~~~~~~~~ ERREUR ~~~~~~~~~~");
				ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				ihmServer.affiche("");
	    }
		
		for(int i=0;i<sockets.size();i++)
		{
			try
			{
				PrintStream socOut = new PrintStream(sockets.get(i).getOutputStream());
				socOut.println(texte);
			}
			catch (Exception e)
			{
					System.err.println("Error in Server::affiche:" + e);
					ihmServer.affiche("");
					ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					ihmServer.affiche("~~~~~~~~~~ ERREUR ~~~~~~~~~~");
					ihmServer.affiche("~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					ihmServer.affiche("");
		    }
		}
	}

	public void add(Socket socket) {
		sockets.add(socket);
	}

	public String getHistorique() {
		return historique;
	}

	public void remove(Socket socket) {
		sockets.remove(socket);
	}
}
