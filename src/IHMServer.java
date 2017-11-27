import java.awt.*;
import java.awt.event.*;
import java.net.ServerSocket;

import javax.swing.*;

@SuppressWarnings("serial")
public class IHMServer extends JFrame implements ActionListener
{
	
	private JButton boutton;
	private JTextArea text;
	private JScrollPane scrollPane;
	
	public IHMServer()
	{
		super();
		this.setTitle("Serveur NSM");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(700,400);
		this.setLocationRelativeTo(null);
		this.setResizable(true);
		
			JPanel principal = new JPanel();
			principal.setBackground(Color.GRAY);
			GridLayout gridLayout = new GridLayout(2,1);
			gridLayout.setHgap(50);
			gridLayout.setVgap(50);
			principal.setLayout(gridLayout);
			
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
				boutton = new JButton("Cliquez pour connecter");
				boutton.setFont(font);
				boutton.addActionListener(this);

			principal.add(scrollPane);
			principal.add(boutton);
			
		this.setContentPane(principal);
		this.setVisible(true);
	}
	
	public static void main(String[] args)
	{
		new IHMServer();
	}

	public void actionPerformed(ActionEvent e)
	{
		final int port = Server.PORT;
		try
		{
			ServerSocket test = new ServerSocket(port);
			test.close();
		}
		catch (Exception e1)
		{
			System.out.println("Le port "+ port +" est reservé.");
			return;
		}
		new Server(5001,this);
	}
	
	public void affiche (String texte)
	{
		text.append(texte+'\n');
		JScrollBar vertical = scrollPane.getVerticalScrollBar();
		vertical.setValue( vertical.getMaximum() );
	}
}