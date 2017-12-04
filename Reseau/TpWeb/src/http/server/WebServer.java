///A Simple Web Server (WebServer.java)

package http.server;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

/**
 * Example program from Chapter 1 Programming Spiders, Bots and Aggregators in
 * Java Copyright 2017 by FloLo
 * 
 * WebServer is a very simple web-server. Any request is responded with a very
 * simple web-page.
 * 
 * @author FloLo
 * @version 1.0
 */
public class WebServer {

  /**
   * WebServer constructor.
   */
  protected void start() {
	  
    ServerSocket s;

    System.out.println("Webserver starting up on port 80");
    System.out.println("(press ctrl-c to exit)");
    try {
      // create the main server socket
      s = new ServerSocket(3000);
    } catch (Exception e) {
      System.out.println("Error: " + e);
      return;
    }

    System.out.println("Waiting for connection");
    for (;;) {
      try {
        // wait for a connection
        Socket remote = s.accept();
        // remote is now the connected socket
        System.out.println("Connection, sending data.");
        BufferedReader in = new BufferedReader(new InputStreamReader(
            remote.getInputStream()));
        PrintStream out = new PrintStream(remote.getOutputStream());

        // read the data sent. We basically ignore it,
        // stop reading once a blank line is hit. This
        // blank line signals the end of the client HTTP
        // headers.
        String str = ".";
        String message = "";
        while (!str.equals("")){
          str = in.readLine();
          message += str;
        }
        System.out.println(message);
        
        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
   
        if(message.substring(0, 3).equals("GET")){
        		String file="";
        		if(message.substring(5, 6).equals(" ")){
        			file = "pageParDefaut.html";
        		}
        		else{
	        		int i = 5;
	        		while(message.charAt(i)!=' '){
	        			file+=message.charAt(i);
	        			i++;
	        		}
        		}
        		
                File f = new File(file);
                if(f.exists()){

        	        // Send the response
        	        // Send the headers
        	        out.println("HTTP/1.0 200 OK");
        	        
            		String type = file.substring(file.indexOf(".")+1);

            		if(type.equals("html") || type.equals("txt")){
            	        out.println("Content-Type: texte html/txt");
            		}
            		else if(type.equals("jpg")){
            	        out.println("Content-Type: image jpg/png");
            		}
            		else if(type.equals("mp3")){
            	        out.println("Content-Type: musique mp3");
            		}
               		else if(type.equals("wmv")){
            	        out.println("Content-Type: video wmv");
            		}
        	        out.println("Server: Bot");
        	        // this blank line signals the end of the headers
        	        out.println("");
        	  
        	        // Send the image
        	        Path path = Paths.get(file);
        	        byte[] data = Files.readAllBytes(path);
        	        out.write(data);
        	        out.flush();
                }
                else{
        	        // Send the response
        	        // Send the headers
        	        out.println("HTTP/1.0 404 Not Found");
        	        out.println("Content-Type: text/html");
        	        out.println("Server: Bot");
        	        // this blank line signals the end of the headers
        	        out.println("");
        	        // Send the HTML page
        	        out.println("<H1>Fichier introuvable</H2>");
        	        out.flush();
                }
        	
        }
        
        else if(message.substring(0, 4).equals("HEAD")) {
        	if(message.substring(4, 5).equals("/")){
        		String file="";
        		int i = 5;
        		while(message.charAt(i)!=' '){
        			file+=message.charAt(i);
        			i++;
        		}
        		System.out.println("file ="+file);
        		
        		
                File f = new File(file);
                if(f.exists()){
        	        // Send the response
        	        // Send the headers
        	        out.println("HTTP/1.0 200 OK");
        	        out.println("Content-Type: text/html");
        	        out.println("Server: Bot");
        	        // this blank line signals the end of the headers
        	        out.println("");
        	        // Send the HTML page
        	        FileInputStream fis = new FileInputStream(file);
        	        byte[] buf = new byte[8];
        	        String texte = "";
        	        while (fis.read(buf) >= 0) {
        	        	for (byte bit : buf) {
           	        	 texte += (char) bit;
        	        	}
        	        }
        	        fis.close();
        	        
        	        int start = message.indexOf("<head>");
        	        int end = message.indexOf("</head>");
        	        texte = texte.substring(start, end + 8);
        	        
        	        out.println(texte);
        	        out.flush();
                }
                else{
        	        // Send the response
        	        // Send the headers
        	        out.println("HTTP/1.0 404 Not Found");
        	        out.println("Content-Type: text/html");
        	        out.println("Server: Bot");
        	        // this blank line signals the end of the headers
        	        out.println("");
        	        // Send the HTML page
        	        out.println("<H1>Fichier introuvable</H2>");
        	        out.flush();
                }
        	}
	        
        }
        
        
        
        

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        remote.close();
      } catch (Exception e) {
        System.out.println("Error: " + e);
      }
    }
  }

  /**
   * Start the application.
   * 
   * @param args
   *            Command line parameters are not used.
   */
  public static void main(String args[]) {
    WebServer ws = new WebServer();
    ws.start();
  }
}
