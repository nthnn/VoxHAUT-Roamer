import * as React from 'react';
import * as ReactDOMClient from 'react-dom/client';

import MessageOptionsDialog from './MessageOptionsDialog';

export default class FloatingCircleButton extends React.Component {
    showOptions(): void {
        let root = ReactDOMClient.createRoot(document.getElementById('dialog-options'));
        $("#dialog-options")
            .removeClass("d-none")
            .removeClass("animate__slideOutUp");

        root.render(<MessageOptionsDialog />);
        $("#dialog-options").addClass("animate__slideInDown");
    }

    render() {
        return (
            <div className="floating-btn animate__animated animate__slow animate__fadeIn"
                align="center"
                onClick={this.showOptions}>

                <img src="images/ic-add-btn.png" width="28" />
            </div>
        );
    }
}