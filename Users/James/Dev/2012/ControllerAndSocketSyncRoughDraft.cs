[James] The tearoff-asynch-controller needed to signal the socket communication signals even if aborted. This required creating a class to do it when a refobj goes out of scope since cleanup is not sufficient. 
I'm not clear on why this is not also a problem for the non-tear-off thread. It might be the way the test is designed, but there is a separate CAR (337080) to make this more robust in general.
The test sequence wouldn't run for me in the sequential model because it referred to non-existing test socket properties. I fixed that and attached the modified sequence file: Offline Persistence Aborting_Fixed.seq.

Note: if you use xml (new thread) reports, you get a runtime error about mismatched xml tags. I ran it with the RTE option set to automatically goto cleanup for XML and with text reports (new thread) to avoid RTEs. I also tested it with offline logging enabled (new thread).


[Test Impact] Validator:






internal class SocketRecord : IComparable<SocketRecord>
    {
        public SocketRecord(Thread thread, int socketIndex) 
        {
            this.thread = thread;
            this.socketIndex = socketIndex;
        }

        public Thread  thread;
        public int socketIndex;
        public string pendingRequest;

        public int CompareTo(SocketRecord other)
        {
            return socketIndex - other.socketIndex;
        }
    }

    internal class ControllerRequest
    {
        public ControllerRequest(Thread thread, int socketIndex, string synchronizationPointName)
        {
            this.thread = thread;
            this.socketIndex = socketIndex;
            this.synchronizationPointName = synchronizationPointName;
        }

        public Thread thread;
        public int socketIndex;
        public string synchronizationPointName;
    }
    
    public class ControllerAndSocketSynchronization
    {
        private Engine mEngine = null;
        private List<SocketRecord> mSocketRecords = new List<SocketRecord>();
        private List<ControllerRequest> mControllerRequests = new List<ControllerRequest>();
        private Thread mController = null;
        private SyncManager mSyncManager = null;

        private Notification waitForControllerNotification;

        public ControllerAndSocketSynchronization(Engine engine)
        {
            mEngine = engine;
            mSyncManager = engine.GetSyncManager("") as SyncManager;
            

        }

        public void SetController(Thread thread)
        {
            mController = thread;
        }

        public void AddSocket(Thread thread, int socketIndex)
        {
            mSocketRecords.Add(new SocketRecord(thread, socketIndex));
            mSocketRecords.Sort();
        }

        public void SynchronizeWithController(Thread thread, int socketIndex, string synchronizationPointName)
        {
            mControllerRequests.Add(new ControllerRequest(thread, socketIndex, synchronizationPointName));

        }

        public void WaitForSockets(string synchronizationPointName)
        {

        }

        public void AllowSocketsToContinue(string synchronizationPointName, bool releaseSequentially)
        {

        }
    }
Thx,
- James

