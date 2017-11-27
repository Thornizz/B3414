import javax.swing.*;

@SuppressWarnings("serial")
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
	
	public void go (String pseudo)
	{
		this.setTitle("NSM - "+pseudo);
		this.setContentPane(new DiscussionClient(pseudo,this));
		this.setVisible(true);
	}
	
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
