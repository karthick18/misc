#!/usr/bin/env python3

import argparse
from pipeline_interface import IPipeline
from dag import DAG, DAGError
from task import Task

class Pipeline(IPipeline):
    """
    Concrete implementation of a pipeline.
    """

    def __init__(self, tasks: list):
        self.tasks = tasks
        self.dag = DAG(tasks)
        self.dag.build_dag()

    def run(self) -> int:
        """
        Runs the pipeline on the provided data and returns the status.
        Args:
            None
        Returns:
            status: The status of running the pipeline.
        """
        return self.dag.execute_dag()

    def setup(self):
        pass


if __name__ == "__main__":
    # Set up argument parser
    parser = argparse.ArgumentParser(description="Run the pipeline with a specified number of tasks.")
    parser.add_argument('-n', type=int, default=10, help="Number of tasks to generate (default: 10)")
    args = parser.parse_args()

    # Validate n
    if args.n <= 0:
        parser.error("n must be a positive integer")

    # Example usage
    def task_worker(data: dict) ->int:
        """ returns status of task execution """
        print(f'Executing task with data {data}')
        return 0

    try:
        n = args.n
        num_tasks = 2 * n + 1
        tasks: list[Task] = []
        for t in range(num_tasks):
            task: Task = Task(f"task{t}", [], task_worker, data={f"input{t}": t})
            tasks.append(task)

        for i, t in enumerate(tasks):
            child1: int = 2 * i + 1
            child2: int = 2 * i + 2
            if child1 < num_tasks:
                t.dependencies.append(tasks[child1])
            if child2 < num_tasks:
                t.dependencies.append(tasks[child2])

        pipeline = Pipeline(tasks)
        status = pipeline.run()
        print(f"Pipeline executed with status: {status}")

        # Demonstrating circular dependency error
        tasks[len(tasks) - 1].dependencies = [tasks[0]]
        pipeline = Pipeline(tasks)
        status = pipeline.run()
    except DAGError as e:
        print(f"Pipeline failed as expected. DAG Error: {e}")
    except ValueError as e:
        print(f"Value Error: {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        print("Pipeline should have failed with circular dependency DAG Error")