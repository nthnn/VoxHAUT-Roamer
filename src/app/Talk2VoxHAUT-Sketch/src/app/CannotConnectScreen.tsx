import * as React from 'react';

export default class CannotConnectScreen extends React.Component {
    reload(): void {
        $("#cannot-connect-section")
            .removeClass("animate__fadeIn")
            .addClass("animate__fadeOut");

        setTimeout(()=> window.location.reload(), 1200);
    }

	render() {
		return (
			<div className="d-flex bg-white h-100 animate__animated animate__slow animate__fadeIn" id="cannot-connect-section">
                <div className="my-auto mx-auto justify-content-center align-items-center">
                    <center>
                        <img
	        				src="images/voxhaut-error-mascot.png"
	            			width="180" />
			            <br/><br/>
                        <p>Something went wrong.</p>

                        <br/>
                        <button className="btn btn-outline-primary" onClick={this.reload}>Re-try</button>
                    </center>
                </div>
            </div>
        );
    }
}