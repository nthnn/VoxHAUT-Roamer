import * as React from 'react';
import { application } from './App';

export default class MessageOptionsDialog extends React.Component {
    hideOptions(): void {
        $("#dialog-options")
            .removeClass("animate__slideInDown")
            .addClass("animate__slideOutUp");

        setTimeout(()=> {
            $("#dialog-options").addClass("d-none");
            $("#message-options-dialog").remove();
        }, 1200);
    }

	render() {
		return (
            <div id="message-options-dialog">
                <div className="container">
                    <br/><br/>
                    <h2>Messages</h2>
                    <hr/>

                    <center>
                        <button className="btn btn-primary w-100" onClick={()=> application.sendMessageToVoxHAUT("temp", "What is the temperature right now?")}>Temperature</button>
                        <br/><br/>
                        <button className="btn btn-primary w-100" onClick={()=> application.sendMessageToVoxHAUT("humid", "What is the humidity right now?")}>Humidity</button>
                        <hr/>
                        <button className="btn btn-outline-danger w-100" onClick={this.hideOptions}>Close</button>
                    </center>
                </div>
            </div>
        );
    }
}