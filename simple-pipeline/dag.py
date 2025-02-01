from dag_interface import IDAGPipeline
from task import Task

class DAGError(Exception):
    pass

class DAG(IDAGPipeline):
    """
    Concrete implementation of a DAG-based pipeline.
    """

    def __init__(self, tasks: list):
        self.tasks = tasks
        self.dag = None

    def build_dag(self) -> None:
        """
        Constructs the Directed Acyclic Graph (DAG) for the pipeline.
        """
        self.dag = {}
        for task in self.tasks:
            self.dag[task.name] = task

    def execute_dag(self) -> int:
        """
        Executes the DAG pipeline and returns status
        Args:
            None
        Returns:
            int: The status of executing the DAG pipeline.
        """
        # Topological sort to determine the execution order
        execution_order = self.topological_sort()

        # Execute the tasks in the determined order
        for task_name in execution_order:
            task = self.dag[task_name]
            status: int = task.execute()
            if status != 0:
                raise Exception(f"Task {task.name} failed with status {status}")

        return 0

    def topological_sort(self):
        """
        Performs a topological sort on the DAG to determine the execution order.
        Returns:
            list: The topologically sorted list of task names.
        """
        in_degree = {node: 0 for node in self.dag}
        node: str
        task: Task
        for node, task in self.dag.items():
            dep: Task
            for dep in task.dependencies:
                in_degree[dep.name] += 1

        queue = [node for node in in_degree if in_degree[node] == 0]
        execution_order = []
        while queue:
            node: str = queue.pop(0)
            del in_degree[node]
            execution_order.append(node)
            dep: Task
            for dep in self.dag[node].dependencies:
                in_degree[dep.name] -= 1
                if in_degree[dep.name] == 0:
                    queue.append(dep.name)

        # validate if there are cyclical deps
        if len(in_degree) != 0:
            raise DAGError("Cyclical dependencies detected in the DAG")

        return execution_order
