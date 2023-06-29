import * as React from 'react';

export default class FloatingCircleButton extends React.Component {
    render() {
        return (
            <div className="floating-btn animate__animated animate__slow animate__fadeIn" align="center">
                <img src="images/ic-add-btn.png" width="28" />
            </div>
        );
    }
}