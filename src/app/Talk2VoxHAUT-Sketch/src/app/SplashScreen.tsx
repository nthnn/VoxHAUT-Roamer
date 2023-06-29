import * as React from 'react';

export default class SplashScreen extends React.Component {
	render() {
		return (
			<div className="d-flex bg-white h-100 animate__animated animate__slow" id="splash-screen">
                <div className="my-auto mx-auto justify-content-center align-items-center">
                    <center>
        				<img
	        				src="images/voxhaut-mascot.png"
	            			width="180" />
			            <br/><br/>

    				    <h1>Talk-2-VoxHAUT</h1>
            			<p className="text-muted">Developed by Group 5</p>
                    </center>
                </div>
			</div>
		);
	}
}