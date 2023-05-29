import * as React from 'react';

export default class LoadingScreen extends React.Component {
	render() {
		return (
			<div className="d-flex bg-white h-100 animate__animated animate__slow animate__fadeIn" id="splash-screen">
                <div className="my-auto mx-auto justify-content-center align-items-center">
                    <center>
                        <img
                            className="rotating"
                            width="50"
                            src="https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fnest.com%2Fsupport%2Fimages%2Fmisc-assets-icons%2Floading-blue-icon.png&f=1&nofb=1&ipt=8d2809ab895926bd8c57ab9906a3f30b66175ea3a16cc1839d965982dd5ab985&ipo=images" />
                        <br/><br/>
                        <p>Connecting to JogRat...</p>
                    </center>
                </div>
            </div>
        );
    }
}