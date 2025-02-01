from abc import ABC, abstractmethod

class IPipeline(ABC):
    """
    Abstract base class for pipeline interfaces.
    """

    @abstractmethod
    def run(self) -> int:
        """
        Runs the pipeline and returns status
        Args:
            None
        Reurns:
            int: The status of running the pipeline.
        """
        raise NotImplementedError("run() method must be implemented by concrete subclass.")
    
    @abstractmethod
    def setup(self):
        """
        Performs any necessary setup for the pipeline.
        """
        raise NotImplementedError("setup() method must be implemented by concrete subclass.")