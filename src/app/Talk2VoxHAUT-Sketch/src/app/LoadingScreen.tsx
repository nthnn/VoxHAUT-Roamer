import * as React from 'react';

export default class LoadingScreen extends React.Component {
	render() {
		return (
			<div
                className="d-flex bg-white h-100 animate__animated animate__slow animate__fadeIn"
                id="loading-screen">
                
                <div className="my-auto mx-auto justify-content-center align-items-center">
                    <center>
                        <img
                            className="rotating"
                            width="50"
                            src="images/loading-circle.png" />
                        <br/><br/>
                        <p>Connecting to VoxHAUT...</p>
                    </center>
                </div>
            </div>
        );
    }
}