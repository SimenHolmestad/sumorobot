package Plab;

import java.io.IOException;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class BluetoothMain {
	
	public class MyMain extends Application {
	    @Override
	    public void start(Stage primaryStage) throws IOException {
	        FXMLLoader fxmlLoader = new FXMLLoader();
	        Parent root = (Parent) fxmlLoader.load(this.getClass().getResourceAsStream("BluetoothApp.fxml"));
	        primaryStage.setScene(new Scene(root));
	        primaryStage.show();
	    }
	       	
	    public void main(String[] args) {
	        launch(args);
	    }
	}
	
	

}
