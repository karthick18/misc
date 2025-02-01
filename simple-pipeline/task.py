class Task:
    """
    Represents a single task in the DAG pipeline.
    """

    def __init__(self, name: str, dependencies: list, execute_func: callable, data: dict = {}):
        self.name = name
        self.dependencies = dependencies
        self.execute_func = execute_func
        self.data = data

    def execute(self) -> int:
        """
        Executes the task.
        Args:
            None
        Returns:
            status: The status of running the task
        """
        status: int = self.execute_func(self.data)
        return status