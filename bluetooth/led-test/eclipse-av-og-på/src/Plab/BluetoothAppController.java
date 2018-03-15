package Plab;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.paint.Color;
import javafx.scene.control.Slider;
import javafx.scene.control.ProgressBar;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;


public class BluetoothAppController {
	
	private PlabSerial serialConnection = new PlabSerial();
	
	@FXML
    private TextField serialPortNameField;
	
	@FXML
	void initialize() {
		String portName;
		if(serialConnection.openPLabPort()) {	
		    portName = serialConnection.getOpenPortName();}
		else {
			portName = "No PLab BT device found.";
		};
		serialPortNameField.setText(portName);
		serialConnection.addListener(this, "messageReceived");
	
	
	}
	@FXML
	public void handleStart() {
		serialConnection.sendMessage("p");
		System.out.println("p");
	}
	
	@FXML
	public void handleSlutt() {
		serialConnection.sendMessage("a");
		
	}

}	