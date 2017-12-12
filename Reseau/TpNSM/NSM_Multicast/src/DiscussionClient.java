/**
 * 
 *  Cette classe permet l'affichage d'une discussion c�t� client
 *  @author Lo�c CASTELLON et Florian MUTIN 3IF4
 * 
 */

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DiscussionClient extends JPanel implements ActionListener
{
	private JButton envoyer;
	private JButton deconnexion;
	
	private JTextField textField;
	
	private Client client;
	
	private JTextArea text;
	private JScrollPane scrollPane;
	
	private IHMClient ihmClient;
	/**
	 * @param pseudo le pseudo du client
	 * @param ihmC la fen�tre graphique de la discussion
	 */
	public DiscussionClient(String pseudo, IHMClient ihmC)
	{
		super();
		
		this.setBackground(Color.GRAY);
		GridLayout gridLayout = new GridLayout(2,1);
		gridLayout.setHgap(50);
		gridLayout.setVgap(50);
		this.setLayout(gridLayout);
		
			Font font = new Font("Serif", Font.PLAIN, 20);
		
			//case 1
			text = new JTextArea();
			text.setOpaque(false);
			text.setFont(font);
			text.setText("");
			text.setEditable(false);
			scrollPane = new JScrollPane(text);
			scrollPane.setOpaque(true);
		
			//case 2
			JPanel envoi = new JPanel();
			envoi.setOpaque(false);
			GridLayout gL = new GridLayout(3,1);
			gL.setHgap(50);
			gL.setVgap(20);
			envoi.setLayout(gL);
			
				//case 2.1
				textField = new JTextField();
				textField.setBackground(Color.WHITE);
				textField.setFont(font);
				
				//case 2.2
				envoyer = new JButton("Envoyer");
				envoyer.setOpaque(false);
				envoyer.setFont(font);
				envoyer.addActionListener(this);
				
				//case 2.3
				deconnexion = new JButton("Deconnection");
				deconnexion.setOpaque(false);
				deconnexion.setFont(font);
				deconnexion.addActionListener(this);

			envoi.add(textField);
			envoi.add(envoyer);
			envoi.add(deconnexion);

		this.add(scrollPane);
		this.add(envoi);
		
		client = new Client(pseudo,this);
		this.ihmClient = ihmC;
	}
	/**
	 * Au clic sur le bouton envoyer on envoit le texte si un texte est renseign�
	 * Au clic sur le bouton deconnection on envoit le message de d�connexion
	 */
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource() == envoyer)
		{
			String texte = textField.getText();
			if(!texte.isEmpty()){
				textField.setText("");
				client.envoyer(texte);
			}
		}
		else if (e.getSource() == deconnexion)
		{
			client.envoyer(Server.DECONNEXION);
			ihmClient.start();
		}
	}
	/**
	 * Affiche un message
	 * @param texte le message � afficher
	 */
	public void affiche (String texte)
	{
		text.append(texte+'\n');
		JScrollBar vertical = scrollPane.getVerticalScrollBar();
		vertical.setValue( vertical.getMaximum() );
	}
}
