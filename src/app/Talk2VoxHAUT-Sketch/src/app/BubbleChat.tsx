import * as React from 'react';

export default class LoadingScreen extends React.Component {
    super(props) {
        this.props = props;
    }

    render() {
        return (
            <div className="container">
                <div className="row">
                    {this.props.sender !== "VoxHAUT" && <div className="col-1"></div>}
 
                    <div className="col-11">
                        <div className="card card-body border-primary border animate__animated animate__flipInX">
                           <div className="container">
                                <div className="row">
                                    <div className="col-3">
                                        <img
                                            src={this.props.sender !== "VoxHAUT" ? "images/user-placeholder.png" : "images/voxhaut-mascot.png"}
                                            width="60" />
                                    </div>

                                    <div className="col-9">
                                        <div className="row">
                                            <div className="col-1"></div>

                                            <div className="col-11">
                                                <div className="chatContent">
                                                    <h3>{this.props.sender}</h3>
                                                    <p>{this.props.message}</p>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>

                    {this.props.sender === "VoxHAUT" && <div className="col-1"></div>}
                </div>
                <br />
            </div>
        );
    }
}