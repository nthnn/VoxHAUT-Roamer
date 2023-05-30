import * as React from 'react';

export default class LoadingScreen extends React.Component {
    super(props) {
        this.props = props;
    }

    render() {
        let classNames = "card card-body border-primary border animate__animated " +
            (this.props.sender !== "JogRat" ? "animate__slideInRight" : "animate__slideInLeft");

        return (
            <div className="container">
                <div className="row">
                    {this.props.sender !== "JogRat" && <div className="col-1"></div>}
 
                    <div className="col-11">
                        <div className={classNames}>
                           <div className="container">
                                <div className="row">
                                    <div className="col-3">
                                        <img
                                            src={this.props.profile}
                                            width="60" />
                                    </div>

                                    <div className="col-9">
                                        <div className="row">
                                            <div className="col-1"></div>

                                            <div className="col-11">
                                                <h3>{this.props.sender}</h3>
                                                <p>{this.props.message}</p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>

                    {this.props.sender === "JogRat" && <div className="col-1"></div>}
                </div>
                <br />
            </div>
        );
    }
}