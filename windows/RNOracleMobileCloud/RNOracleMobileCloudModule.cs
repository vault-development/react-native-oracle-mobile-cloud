using ReactNative.Bridge;
using System;
using System.Collections.Generic;
using Windows.ApplicationModel.Core;
using Windows.UI.Core;

namespace Oracle.Mobile.Cloud.RNOracleMobileCloud
{
    /// <summary>
    /// A module that allows JS to share data.
    /// </summary>
    class RNOracleMobileCloudModule : NativeModuleBase
    {
        /// <summary>
        /// Instantiates the <see cref="RNOracleMobileCloudModule"/>.
        /// </summary>
        internal RNOracleMobileCloudModule()
        {

        }

        /// <summary>
        /// The name of the native module.
        /// </summary>
        public override string Name
        {
            get
            {
                return "RNOracleMobileCloud";
            }
        }
    }
}
