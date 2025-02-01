from abc import ABC, abstractmethod

class IDAGPipeline(ABC):
    """
    Abstract base class for DAG-based pipeline interfaces.
    """

    @abstractmethod
    def build_dag(self) -> None:
        """
        Constructs the Directed Acyclic Graph (DAG) for the pipeline.
        """
        raise NotImplementedError("build_dag() method must be implemented by concrete subclass.")

    @abstractmethod
    def execute_dag(self) -> int:
        """
        Executes the DAG pipeline and returns the status
        Args:
            None
        Returns:
            int: The status of executing the DAG pipeline.
        """
        raise NotImplementedError("execute_dag() method must be implemented by concrete subclass.")
