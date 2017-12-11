import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class AcceuilClient extends JPanel implements ActionListener
{
	private JButton boutton;
	private JTextField textField;
	private IHMClient ihmClient;
	
	public AcceuilClient(IHMClient ihmC)
	{
		super();
		
		this.ihmClient = ihmC;
		
		this.setBackground(Color.GRAY);
		GridLayout gridLayout = new GridLayout(4,1);
		gridLayout.setHgap(50);
		gridLayout.setVgap(50);
		this.setLayout(gridLayout);
		
			Font font = new Font("Serif", Font.PLAIN, 36);
		
			//case 1
			JTextArea text1 = new JTextArea();
			text1.setOpaque(false);
			text1.setFont(font);
			text1.setText("Bienvenue sur NSM le nouveau tchat au top.");
			text1.setEditable(false);
		
			//case 2
			JTextArea text2 = new JTextArea("Entre ton pseudo ci dessous :");
			text2.setOpaque(false);
			text2.setFont(font);
			text2.setEditable(false);
		
			//case 3
			textField = new JTextField();
			textField.setBackground(Color.WHITE);
			textField.setFont(font);
		
			//case 4
			boutton = new JButton("C'est parti!");
			boutton.setOpaque(false);
			boutton.setFont(font);
			boutton.addActionListener(this);

		this.add(text1);
		this.add(text2);
		this.add(textField);
		this.add(boutton);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		String pseudo = textField.getText();
		if(!pseudo.isEmpty())
		{
			ihmClient.go(pseudo);
		}
	}
}
