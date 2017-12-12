/**
 * 
 *  Cette classe crée une interface graphique pour la discussion
 *  @author Loïc CASTELLON et Florian MUTIN 3IF4
 * 
 */

import javax.swing.*;

public class IHMClient extends JFrame
{

	public IHMClient()
	{
		super();
		this.setTitle("NSM");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(700,400);
		this.setLocationRelativeTo(null);
		this.setResizable(true);
		this.setContentPane(new AcceuilClient(this));
		this.setVisible(true);
	}
	/**
	 * Modifie le titre de la fenêtre graphique
	 * @param pseudo pseudo du client
	 */
	public void go (String pseudo)
	{
		this.setTitle("NSM - "+pseudo);
		this.setContentPane(new DiscussionClient(pseudo,this));
		this.setVisible(true);
	}
	/**
	 * Rend visible la fenêtre graphique
	 */
	public void start ()
	{
		this.setContentPane(new AcceuilClient(this));
		this.setVisible(true);
	}
	
	public static void main(String[] args)
	{
		new IHMClient();
	}
}
