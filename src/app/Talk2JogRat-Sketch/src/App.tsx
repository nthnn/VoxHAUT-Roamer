import * as React from 'react';
import * as ReactDOMClient from 'react-dom/client';

import SplashScreen from './SplashScreen';

ReactDOMClient.createRoot(document.getElementById('main')).render(<SplashScreen />);