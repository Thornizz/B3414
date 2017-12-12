import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
/**
 * 
 *  Cette classe implémente une fenêtre pour une discussion
 *  @author Loïc CASTELLON et Florian MUTIN 3IF4
 * 
 */
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
	 * Gère les messages sur la fenêtre de discussion
	 * @param pseudo le pseudo du client
	 * @param ihmC la fenêtre graphique de la discussion
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
		
		client = new Client(Server.IP,Server.PORT,pseudo,this);
		this.ihmClient = ihmC;
	}
	/**
	 * Capte les clics de souris sur les boutons et gère les effets des boutons
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
	 * Affiche un message sur la discussion
	 * @param texte le message à afficher
	 */
	public void affiche (String texte)
	{
		text.append(texte+'\n');
		JScrollBar vertical = scrollPane.getVerticalScrollBar();
		vertical.setValue( vertical.getMaximum() );
	}
}
